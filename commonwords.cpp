#include  <iostream>
#include <unordered_map>
#include <string>
#include <vector> 

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {

        unordered_map<string, int> words1frequency ;
        unordered_map<string, int> words2frequency ;
        int count = 0;


        for (auto& word : words1){

            if ( !words1frequency.count(word)) {
              
              words1frequency.insert({word, 1});
                 
        }
        
        else {
             words1frequency[word] = words1frequency[word]+1 ;
        }    
  
        
        }
     for (auto& word : words2){

            if ( !words2frequency.count(word)) {
              
              words2frequency.insert({word, 1});
                 
        }
        
        else {
             words2frequency[word] = words2frequency[word]+1 ;
        }  
     }

    for (auto it = words1frequency.begin(); it != words1frequency.end();) {
        if (it->second != 1){
           it = words1frequency.erase(it);
        }
        else {
            ++it;
        }
    }
     

      for (auto it = words2frequency.begin(); it != words2frequency.end();) {
        if (it->second != 1){
            it = words2frequency.erase(it);
        } else {
            ++it;
        }

      }

    for(auto word : words1frequency){
        
        
        if(words2frequency.count(word.first)){
            count++;
        }
    }
   
    
    
    return count;        
        
    }
};