#include <iomanip>

#include "config.hpp"
#include "adapter.hpp"
#include "types.hpp"

namespace nfcdoorz {
  using namespace std;

  bool Adapter::connect() {
    return tagInterface.connect();
  }
  bool Adapter::disconnect() {
    return tagInterface.disconnect();
  }

  bool Adapter::authenticatePICC(nfc::Key &key) {
    AppID_t aid = {0, 0, 0};
    return authenticateAppByID(aid, key);
  }

  bool Adapter::authenticatePICC() {
    AppID_t aid = {0, 0, 0};
    return visit(overloaded {
      [this, &aid](monostate _arg) -> bool {
        return visit([this, &aid](auto &key) {
          cout << "authenticatePICC config.picc.key" << endl;
          return authenticateAppByID(
            aid,
            key
          );
        }, config.picc.key);
      },
      [this, &aid](auto key) -> bool {
        cout << "authenticatePICC _overriddenMasterKey" << endl;
        return authenticateAppByID(
          aid,
          key
        );
      }
    }, _overriddenMasterKey);
  }

  bool Adapter::authenticateAppByID(AppID_t &aid, nfc::Key &key) {
    MifareDESFireAID api_aid = mifare_desfire_aid_new(aid[0] | (aid[1] << 8) | (aid[2] << 16));
    if (!tagInterface.select_application(api_aid)) return false;
    _aid = aid;
    CLEAN_KEY MifareDESFireKey api_key = key.diversify
      ? key.deriveKey(_uid, aid)
      : key;
    return tagInterface.authenticate(0, api_key);
  }

  bool Adapter::authenticateApp(string app_name, string key_name) {
    for (auto &app: config.apps) {
      if (app.name == app_name) {
        for (auto &key: app.keys) {
          if(visit([this, &key_name, &app](auto &key) {
            if (key.name == key_name) {
              if (authenticateAppByID(app.aid, key)) {
                _app = &app;
              } else {
                _app = nullptr;
              }
              return true;
            }
            return false;
          }, key)) {
            return _app != nullptr;
          }
        }
      }
    }
    return false;
  }

  bool Adapter::changeKey(uint8_t key_id, nfc::Key &new_key, nfc::Key &old_key) {
    CLEAN_KEY MifareDESFireKey api_new_key = new_key.diversify
      ? new_key.deriveKey(_uid, _aid)
      : new_key;
    CLEAN_KEY MifareDESFireKey api_old_key = old_key.diversify
      ? old_key.deriveKey(_uid, _aid)
      : old_key;

    return tagInterface.change_key(key_id, api_new_key, api_old_key);
  }

  bool Adapter::deleteApplication(AppID_t aid) {
    CLEAN_AID MifareDESFireAID api_aid = mifare_desfire_aid_new(aid[0] | (aid[1] << 8) | (aid[2] << 16));
    return tagInterface.delete_application(api_aid);
  }

  bool Adapter::createApplication(AppID_t aid, uint8_t settings, uint8_t numKeys) {
    CLEAN_AID MifareDESFireAID api_aid = mifare_desfire_aid_new(aid[0] | (aid[1] << 8) | (aid[2] << 16));
    _aid = aid;
    return tagInterface.create_application_aes(api_aid, settings, numKeys);
  }

  bool Adapter::setUID(UID_t uid) {
    _uid = uid;
    return true;
  }

  bool Adapter::setUID(string uid_str) {
    size_t len = uid_str.length();
    if (len % 2) return false;
    if (len != _uid.size() * 2) return false;
    for (uint8_t i = 0; i < len; i += 2) {
      _uid[i / 2] = (char2int(uid_str[i]) << 4) | char2int(uid_str[i+1]);
    }
    return true;
  }

  bool Adapter::getUIDFromCard() {
    char *uid = tagInterface.get_uid();
    return setUID(uid);
  }

  UID_t Adapter::getUID() {
    if (all_of(_uid.begin(), _uid.end(), [](uint8_t c){ return c == 0; })) {
      getUIDFromCard();
    }
    return _uid;
  }

  string Adapter::getUIDString() {
    auto uid = getUID();
    stringstream sb("");
    bool rest = false;
    for (auto c: uid) {
      if (rest) sb << ":";
      sb
        << setfill('0')
        << setw(2)
        << hex
        << (int) c;
      rest = true;
    }
    return sb.str();
  }

  bool Adapter::setOverriddenMasterKey(nfc::KeyVariant_t key) {
    visit([this](auto key) {
      _overriddenMasterKey = key;
    }, key);
    return true;
  }

  bool Adapter::setOverriddenMasterKey(string key) {
    _overriddenMasterKey = nfc::KeyAES(key, true);
    return true;
  }

}
