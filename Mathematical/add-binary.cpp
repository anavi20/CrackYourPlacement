// Time Complexity:O(max(length(a),length(b))) Space Complexity: O(max(length(a),length(b)))

class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.length(), m=b.length(), i=n-1, j=m-1;
        string ans = "";
        bool isCarry = false;
        while(i>=0 && j>=0){
            if(a[i] == '1' && b[j] == '1'){
                if(isCarry){
                    ans+= '1';
                }else{
                isCarry = true;
                ans += '0';
                }
                
            }else if ((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1')){
                if(isCarry){
                    ans += '0';
                }else{
                    ans += '1';
                }
            }else{
               if(isCarry){
                    ans += '1';
                    isCarry = false;
                }else{
                    ans += '0';
                } 
            }
            i--;
            j--;
        }
        while(i>=0){
            if(a[i] == '1'){
                if(isCarry){
                    ans+= '0';
                }else{
                    ans+='1';
                }
            }else{
               if(isCarry){
                    ans+= '1';
                    isCarry = false;
                }else{
                    ans+='0';
                } 
            }
            i--;
        }
        while(j>=0){
            if(b[j] == '1'){
                if(isCarry){
                    ans+= '0';
                }else{
                    ans+='1';
                }
            }else{
               if(isCarry){
                    ans+= '1';
                    isCarry = false;
                }else{
                    ans+='0';
                } 
            }
            j--;
        }
        if(isCarry){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};


class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i = a.length() - 1, j = b.length() - 1, isCarry=0;
        
        while(i>=0 || j>=0 || isCarry){
            if(i>=0){
                isCarry += a[i] - '0';
                i--;
            }
            if(j>=0){
                isCarry += b[j] - '0';
                j--;
            }

            ans += isCarry%2 + '0';
            isCarry = isCarry/2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
