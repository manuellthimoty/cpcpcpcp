#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}


int main(){
    int n_case;
    scanf("%d",&n_case);
    int result[n_case];
    for(int i=0;i<n_case;i++){
        int n;
        scanf("%d",&n);
        int a[n];
        int b[n];
        int exist_comfact=0;
        int count_genap=0;
        int count_ganjil=0;

        for(int j=0;j<n;j++){
            scanf("%d",&a[j]);
        }

        for(int j=0;j<n;j++){
            scanf("%d",&b[j]);
        }

        for(int j=0;j<n;j++){
            if((a[j] % 2)==1){
                count_ganjil++;
            }
            else{
                count_genap++;
            }
            for(int k=j+1;k<n;k++){
                if((gcd(a[j],a[k]))>=2){
                    //printf("0\n");
                    exist_comfact=1;
                    break;
                }
            }
        }
        if(exist_comfact==1){
            result[i]=0;
            continue;;
        }
        if(count_genap>=2){
            result[i]=0;
        }
        else if(count_genap==1 && count_ganjil>0){
            result[i]=1;
        }
        else{
            int found=0;
            for(int j=0;j<n && !found;j++){
                for(int k=j+1;k<n;k++){
                    if (gcd(a[j], a[k] + 1) > 1 || gcd(a[j] + 1, a[k]) > 1) {
                        found = 1;
                        break;
                    }
                }
            }
            if(found==1){
                result[i]=1;
            }
            else{
                result[i]=2;
            }
        }
    }
    for(int i=0;i<n_case;i++){
        printf("%d\n",result[i]);
    }
}