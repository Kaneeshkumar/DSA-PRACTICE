class Solution{   
public:    
    int minBitsFlip(int start, int goal) { 
        //Your code goes here

        int num=start^goal;

        int cnum=num;
        int cnt=0;

        while(cnum!=0){
            cnt+=(cnum & 1);
            cnum=cnum>>1;
        }

        return cnt;
        
    }
};