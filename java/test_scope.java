import java.util.*; 

class test_scope{
    public static void main(String args[]){
        // int x;

        // twod_arr = new int[3][3];
        int arr[] = new int[5];

        int twoD[][] = {{1,2,3},{4,5,6},{8,9,10},{1,2,3}};

        for(int i=0;i<4;i++){
            for(int  j=0;j<3;j++){
                System.out.print("Row "+ i + " \n"+twoD[i][j]);
            }
            System.out.println();
        }
    }
}