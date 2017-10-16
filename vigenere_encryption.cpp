#include <cstdio>
#include <string>

using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int alphabetSize = alphabet.size();

string vigenere(string message, string key){
  int keyLength = key.size();
  string result;
  int keyPos=0;
  int posInAlphabet, shift;
  for(char c : message){
    posInAlphabet = static_cast<int>(alphabet.find(c));
    shift = static_cast<int>(alphabet.find(key[keyPos]));
    result.push_back(alphabet[(shift+posInAlphabet)%alphabetSize]);
    keyPos = (keyPos+1)%keyLength;
  }
  return result;
}

int main(){
  string message = "IAMTIREDANDSICKOFWARITSGLORYISALLMOONSHINEITISONLYTHOSEWHOHAVENEITHERFIREDASHOTNORHEARDTHESHRIEKSANDGROANSOFTHEWOUNDEDWHOCRYALOUDFORBLOODFORVENGEANCEFORDESOLATIONWARISHELL";
  string key = "THE";
  string encryptedMessage = vigenere(message, key);
  printf("result: %s\n", encryptedMessage.c_str());
  return 0;
}
