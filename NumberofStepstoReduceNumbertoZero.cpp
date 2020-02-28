//log(n) time o(1) space
int numberOfSteps (int num) {
        int result = 0;
        while (num) {
            result += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return result - 1;
    }

int numberOfSteps (int num) {
        int count=0;
        while(num){
            if(num&1)
            {
                count++;
                 num-=1;
            }
            else{
                count++;
             num/=2;   
            }
            
        }
        return count;
 }