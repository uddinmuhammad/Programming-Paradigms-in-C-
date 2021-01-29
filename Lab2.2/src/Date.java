//given
public class Date {

    private int year, month, dom;

    Date(int year, int month, int dom) {
        this.year = year;
        this.month = month;
        this.dom = dom;
    }

    public String toString() {return month + "/" + dom + "/" + year;}

}
