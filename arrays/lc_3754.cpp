class Solution {
public:
    long long sumAndMultiply(int n) {
        int y=n;
        vector<int> arr;
        int sum=0;

        while(y!=0){
            int last=y%10;
            if(last!=0){
                arr.push_back(last);
            }
            sum+=last;
            y=y/10;
        }

        int p=arr.size();
        long long num=0;
        for(int i=p-1;i>=0;i--){
            num=num*10+arr[i];
        }

        return num*sum;
    }
};