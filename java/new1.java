import java.util.*;
class grandparent{
    int age;
    void tell_age(){
        System.out.println("I am "+ age + "years old");
    }
}
class parent extends grandparent{
    void tell_age(){
        super.tell_age();
        System.out.println("I am 40 years old");
    }
}

class child extends parent{
    void tell_age(){
        System.out.println("I am 20 years old");
        super.tell_age();
    }
}
class new1{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);     
        // System.out.println("ENter al line");
        // String my_string = sc.nextLine();
        // System.out.println(my_string);
        int arr[] = new int[10];
        child my_Child = new child();
        my_Child.tell_age();

    }
}

