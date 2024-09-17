import java.io.File;

import java.io.IOException;
public class CreateFile {
  public static void main(String[] args) {
    try{
    File f1= new File("FileOperations.txt");
    if(f1.createNewFile()){
      System.out.println("File "+ f1.getName() + " is created");
    }
    else{
      System.out.println("file is already existing");
      }
    }//try
    catch(IOException exception){
      System.out.println("An unexpected error is occured.");
      exception.printStackTrace();
    }
  }
  
}  
