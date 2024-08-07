class Solution {
public:
    string numberToWords(int n) {
        if(n==0) return "Zero";

        vector<string> ones = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

        vector<string> tens = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

        vector<string> thousands = {"","Thousand","Million","Billion"};

        string ans;
        int c = 0;
        while(n>0){
           
            if(n%1000!=0){
                string temp = "";
                int num = n%1000; 

                if(num>=100){
                    temp = ones[num/100] + " Hundred ";
                    num%=100;
                }
                if(num>=20){
                    temp+=tens[num/10]+" ";
                    num%=10;
                }
                if(num>0){
                    temp+=ones[num]+" ";
                }
                temp+=thousands[c] + " ";

                ans = temp + ans;
            }
            n/=1000;
            c++;
        }
        return ans.substr(0,ans.find_last_not_of(" ")+1);
    }
};