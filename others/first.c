#include<stdio.h>
#include <stdbool.h>

int main(){
    int N;
    scanf("%d",&N);
    int arr[N];
    int hasiljumlah[N-1];
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    int index=0;
    for(int i=0;i<N-1;i++){
        hasiljumlah[index]=arr[i]+arr[i+1];
        index++;
    }
    int count=1;
    int max_count=0;
    bool berurutan=false;
    for(int i=0;i<N-1;i++){
        count=1;
        if(hasiljumlah[i]==hasiljumlah[i+1]){
            berurutan=true;
        }
        else{
            berurutan=false;
        }
        for(int j=i+1;j<N-1;j++){
            if(berurutan){
                berurutan=false;
                continue;
            }
            else{
                if(hasiljumlah[i]==hasiljumlah[j]){
                    count++;
                    berurutan=true;
                }
            }
        }
        if(count>max_count){
            max_count=count;
        }
    }
    if(max_count==0){
        printf("\n1\n");
        return 0;
    }
    printf("\n%d",max_count);
}