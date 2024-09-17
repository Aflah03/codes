package pack2;//A is in another  package 
import pack1.A;
  public class C extends A{
    public static void main(String[] args) {

      A a = new A();
      // a.m1(); proteccted memebers can only be accesed outside 
      // package using child class reference
      
      C c1 = new C();
      c1.m1();// valid , bcs we are accesing a protected metod in 
              // another package by using the reference of a child 
              // class
              //
      A a2 = new C();
      // a2.m1();//invalid , parent class reference is used

    }

  }
