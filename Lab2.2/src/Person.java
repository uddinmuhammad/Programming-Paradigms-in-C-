//given
public class Person {
    // Note the overloaded constructors
    private Name name;
    private int age;

    Person(Name name, int age) {
        this.name = name;
        this.age = age;
    }
    public String toString() {return name + " (" + age + ")";}

}
