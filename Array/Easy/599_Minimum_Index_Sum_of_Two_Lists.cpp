class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> vect;
        int sum = 2000;
        for(int i=0;i<list1.size();i++){
            for(int j=0;j<list2.size();j++){
                if(list1[i]==list2[j]){
                    if(i+j<sum){
                        vect.clear();
                        vect.push_back(list1[i]);
                        sum = i+j;  
                    }
                    else if(i+j==sum){
                        vect.push_back(list1[i]);
                    }
                    break;
                }
            }
        }
        return vect;
    }
};