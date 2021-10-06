import java.util.Scanner;
class Main {
    public static void main(String[] args) {
        // put your code here
        boolean ascending = true;
        Scanner scn = new Scanner(System.in);
        scn.nextLine();
        int initialValue = scn.nextInt();
        while (scn.hasNext()) {
            int next = scn.nextInt();
            if (next - initialValue < 1) {
                ascending = false;
                break;
            }
            initialValue = next;
        }
        System.out.println(ascending);
    }
}