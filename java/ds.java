public class ds {
    public int findSecondMaximum(int arr[]){
        if(arr ==null || arr.length==0){
            throw new IllegalArgumentException("Invlaid input");
        }
        int max = Integer.MIN_VALUE;
        int second_max = Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++){
            if(arr[i] > max){
                second_max = max;
                max = arr[i];
            }
            
            else if(arr[i] > second_max && arr[i]<max){
                second_max = arr[i];
            }
        }
        return second_max;
    }
    public void moveZeros(int[] arr){
        int n = arr.length;
        for(int i=0;i<arr.length;i++){
            if(arr[i] ==0){
                for(int j=i;j<arr.length-1;j++){
                    arr[j] = arr[j+1];
                }
                // arr[n-1]=0;
                
            }
        }
    }
    public static void main(String[] args){
        int[] arr= {10,0,4,0,6,0,8,3};
        ds my_method = new ds();
    //    System.out.println(my_method.findSecondMaximum(arr));
       my_method.moveZeros(arr);

       for(int i=0;i<arr.length;i++){
        System.out.print(arr[i] + " ");
       }
    }
    
}
