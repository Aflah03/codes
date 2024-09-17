import java.io.File;
import java.io.IOException;
public class FileInfo {
  public static void main(String[] args) {
    File f1 = new File("FileOperationExample.txt");
   try{ f1.createNewFile();
    if(f1.exists()){
      System.out.println("The name of the file is: " + f1.getName());

      //getting path of the file
      System.out.println("File path is: "+ f1.getAbsolutePath());

      System.out.println("iS FILE WRITABLE ? : " + f1.canWrite());


      System.out.println("iS FILE readable ? : " + f1.canRead());

      System.out.println("The size of file in bytes is : " + f1.length());


      
    }
    else{
      System.out.println("the file does not exist");
    }
   }
   catch(IOException e){
    System.out.println("An unexpected error has occured"); 
    e.printStackTrace(); 
   }
  }
}
