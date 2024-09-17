class A{
  private void m1(){
    System.out.println("private m1 method");
  }
  void m2(){
    m1();
  }
}

public class Test {
  public static void main(String[] args) {
    A a = new A();
    // a.m1();//comiple eroror , accesing private method not allowed 
           //from outside the class
    a.m2();
  }
}
