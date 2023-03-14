#include <iostream>
#include <unordered_map>
int main() {
    std::string firstWord, secondWord, result,testWord;
    std::cin >> firstWord >> secondWord;


    // for(int i = 0; i<secondWord.length(); i++)
    // for(int j = 0 ; j<firstWord.length(); j++)
    //  if(secondWord[i] == firstWord[j]){
    //        testWord+= firstWord[j]; firstWord[j] = '`'; break;
    // }

    std::unordered_map<char, int> hash;

    for(int i = 0; i<firstWord.length(); i++){
        hash[firstWord[i]] = int(firstWord[i]);
    }

    for(int i = 0 ; i< secondWord.length();i++)
        if(hash.count(secondWord[i])){
            testWord += hash.at(secondWord[i]);
            hash.erase(hash.at(secondWord[i]));
        }



    result = (testWord == secondWord) ? "Var" : "Nevar";
    std::cout << result;
}