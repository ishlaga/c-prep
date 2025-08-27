class Solution {
public:
    int maxArea(vector<int>& height) {

    int i =0;
    int j = height.size()-1;
    int maxvalue =0;
    while(i<j){
        int width = j-i;
        int length = min(height[i], height[j]);

        int currentvalue = width*length;
        
        if(currentvalue > maxvalue){
            maxvalue = currentvalue;
        }
        (height[i] >= height[j])? j-- : i++ ;
        
    }
    return maxvalue;

    }
};