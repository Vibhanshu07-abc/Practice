class Online {
    String[] arr;
    int i;

    Online() {
        arr = new String[100]; 
        i = 0;
    }

    public void add(String s) {
        if (i < arr.length) {
            arr[i] = s;
            i++;
            System.out.println(s + " has been added");
        } else {
            System.out.println("Library is full");
        }
    }

    void show() {
        System.out.println("The books available are:");
        for (String av : arr) {
            if (av == null) break;
            System.out.println(av);
        }
    }

    void issue(String s) {
        for (int j = 0; j < i; j++) {
            if (arr[j] != null && arr[j].equalsIgnoreCase(s)) {
                System.out.println("The book '" + arr[j] + "' has been issued");
                arr[j] = null;
                return;
            }
        }
        System.out.println("Book not found");
    }

    void Return(String s) {
        add(s);
    }
}

public class Library {
    public static void main(String[] args) {
        Online obj = new Online();

        obj.add("Demonstrate");
        obj.add("Vibhanshu");
        obj.add("Java Learning");

        obj.show();

        obj.issue("Java Learning");
        obj.show();

        obj.Return("Java Learning");
        obj.show();
    }
}
