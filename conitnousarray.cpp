class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       vector<int> sums ;
        int max_value =0;
        int sum = 0;
       for(int num : nums ){

        if (num ==0){
            sum --;
            sums.push_back(sum);
        }
        else{
            sum ++;
            sums.push_back(sum);
        }

       }
        unordered_map<int, int> HasSeen;


        for (int i =0; i < sums.size(); i++){

            if(sums[i] ==0){
                max_value = max(max_value, i+1 );
            }

            if(HasSeen.count(sums[i]) == 0){
                HasSeen[sums[i]]= i;
            }
           
            else if (HasSeen.count(sums[i])){
                max_value = max(max_value, i- HasSeen[sums[i]]);
            }
        
       }
       return max_value;
    }
};
