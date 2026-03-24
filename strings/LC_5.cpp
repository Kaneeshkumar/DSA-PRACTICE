class Solution {
public:
    string longestPalindrome(string s) {
    //     int n=s.size();
    //     int left;
    //     int right;
    //     string ans="";
    //     int st=-1;
    //     int end=-2;
    //     int maxi=INT_MIN;

    //   for(int i=0;i<n-1;i++){
    //     for(int j=n-1;j>i;j--){
    //         left=i;
    //         right=j;
    //         bool ispal=true;
    //         while(left<=right){
    //             if(s[left]==s[right]){
    //                 left++;
    //                 right--;
    //             }else{
    //                 ispal=false;
    //                 break;
    //             }
    //         }
    //         if(ispal){
    //             maxi=max(maxi,j-i+1);
    //             if(maxi==(j-i+1)){
    //                 st=i;
    //                 end=j;
    //                 break;
    //             }
    //         }
    //     }
    //   }
    //   if(st==-1 && end==-2){
    //     ans+=s[0];
    //     return ans;
    //   }

    //   for(int i=st;i<=end;i++){
    //     ans+=s[i];
    //   }
    //   return ans;

    int n=s.length();
    int start=0;
    int maxlen=1;
    for(int i=0;i<n;i++){
        int left=i;
        int right=i;

        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1>maxlen){
                start=left;
                maxlen=right-left+1;
            }
            left--;
            right++;
        }

        left=i;
        right=i+1;

        while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>maxlen){
                start=left;
                maxlen=right-left+1;
            }
            left--;
            right++;
        }

        }
        return s.substr(start,maxlen);
    
    }
};