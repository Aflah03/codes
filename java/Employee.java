import java.util.*;


public class Employee {
    String name;
    int age;
    String phone_number;
    String  addres;
    String salary;
    Employee(String name, int age, String phone_number, String addres, String salary) {
        this.name = name;
        this.age = age;
        this.phone_number = phone_number;
        this.addres = addres;
        this.salary = salary;

    }
    void dispay_details(){
        System.out.println("Name: " + name;
        System.out.println("Age: " + age);
        System.out.println("Phone number: " + phone_number);
        System.out.println("Addres: " + addres);
        System.out.println("Salary: " + salary);

    }
}
class Officer extends Employee{
    String specialization;
    Officer(String name, int age, String phone_number, String addres, String salary,String specialization) {
        super(name, age, phone_number, addres, salary);
        this.specialization = specilization;
    }
    void    dispay_details(){
        System.out.println("Name: " + name;
        System.out.println("Age: " + age);
        System.out.println("Phone number: " + phone_number);
        System.out.println("Addres: " + addres);
        System.out.println("Salary: " + salary);
        System.out.println("Specialization: " + specialization);

    }
}

    



class  pr2_lab{
    public static void Main(String[] args){
        Employee emp1 = new Employee("Aflah", 20, "9074130869","poonthotathil", 200000000);
        Officer officer1 =new Officer("Aflah", 20, "9074130869","poonthotathil", 200000000,"Secetary");
        System.out.println(emp1.salary);

        officer1.dispay_details();
    }
}