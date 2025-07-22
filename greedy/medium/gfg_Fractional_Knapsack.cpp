// class implemented

struct Item{
    int value;
    int weight;
};


// class Solution {
//   public:
//     double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
//         vector<vector<double>> newVal(val.size(),vector<double>(3, 0.0));
//         for(int i=0;i<val.size();i++){
//             newVal[i][0] = (val[i]*1.0)/(wt[i]*1.0);
//             newVal[i][1] = wt[i];
//             newVal[i][2] = val[i];
//         }
//         sort(newVal.begin(),newVal.end(),[](const vector<double> &a, const vector<double> &b){
//             return a[0]>b[0];
//         });
//         double sum=0,ans=0;
//         int i=0;
//         while(i<val.size() && sum+newVal[i][1]<capacity*1.0){
//             sum+=newVal[i][1];
//             ans+=newVal[i][2];
//             i++;
//         }

//         if(i<val.size() && sum!=capacity*1.0){
//             ans+=(capacity-sum)*newVal[i][0];
//         }
//         return ans;
//     }
// };

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<Item> items(n);
        for(int i=0;i<val.size();i++){
            items[i] = {val[i],wt[i]};
        }
        sort(items.begin(),items.end(),[](const Item &a, const Item &b){
            double r1 = a.value*1.0/a.weight*1.0;
            double r2 = b.value*1.0/b.weight*1.0;
            return r1>r2;
        });
        double sum=0,ans=0;
        int i=0;
        while(i<val.size() && sum+items[i].weight<capacity*1.0){
            sum+=items[i].weight*1.0;
            ans+=items[i].value*1.0;
            i++;
        }

        if(i<val.size() && sum!=capacity*1.0){
            ans+=(items[i].value*1.0)/items[i].weight*(capacity-sum);
        }
        return ans;
    }
};
