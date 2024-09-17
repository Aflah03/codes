import java.util.*;


 class Employee{
    String name;
    int age;
    String phone_number;
    String address;
    double salary;

    Employee(String name,int age, String phone_number, String address, double salary){
        this.name = name;
        this.age = age;
        this.phone_number = phone_number;
        this.address = address;
        this.salary   = salary;
    }
    void print_salary(){
        System.out.println("the salary is : "+ salary);
    }

}
     class Officer extends  Employee {
            String specialization;
            Officer(String name,int age, String phone_number, String address, double salary,String specialization){

            super(name, age, phone_number, address, salary);
            this.specialization = specialization;

            }
    }


class  pr2{
    public static void main(String[] args){
        Employee emp1 = new Employee("Aflah", 20, "9074130869","poonthotathil", 200000000);
        Officer officer1 =new Officer("Aflah", 20, "9074130869","poonthotathil", 200000000,"Secetary");
        System.out.println(emp1.salary);
        System.out.println("\nOfficer Details:");
        System.out.println("Name: " + officer1.name);
        System.out.println("Age: " + officer1.age);
        System.out.println("Phone Number: " + officer1.phone_number);
        System.out.println("Address: " + officer1.address);
        officer1.print_salary();
        System.out.println("Specialization: " + officer1.specialization);
    }
}
