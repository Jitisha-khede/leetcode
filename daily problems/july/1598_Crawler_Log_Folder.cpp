class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="./"){
                //do nothing 
            }
            else if(logs[i]=="../" && count>0){
                count--;
            }
            else if(logs[i]!="./" && logs[i]!="../"){
                count++;
            }
        }
        return count;
    }
};