class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack;
        for(const string& op : operations){
            
            if(op=="C"){
                stack.pop();            
            }
            else if(op=="+"){
                int elem1 = stack.top();
                stack.pop();
                int elem2 = elem1+stack.top();
                stack.push(elem1);
                stack.push(elem2);
            }
            else if(op=="D"){
                int doubl = stack.top()*2;
                stack.push(doubl);
            } 
            else{
                stack.push(stoi(op));
            }   
        }
        int sum=0;
            while(!stack.empty()){
                cout<<stack.top()<<" ";
                sum+=stack.top();
                stack.pop();
            }   
        return sum;
    }
};