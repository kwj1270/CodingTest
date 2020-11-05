import com.sun.jdi.IntegerType;
import javafx.scene.control.TableColumn;

import java.util.*;
import java.util.stream.Collectors;

public class Order {
    public static void main(String[] args) {
        int [] money = {100000, 900, 6000, 5200, 31000, 8000, 10000, 100};
        int [] coupon = {10, 5, 20, 4, 90, 40, 32};
        solution(money, coupon);
    }

    public static int solution(int[] money, int[] coupon){
        int answer =0;
        ArrayList<Integer> moneyList = (ArrayList)Arrays.stream(money).boxed().collect(Collectors.toList());
        ArrayList<Integer> couponList = (ArrayList)Arrays.stream(coupon).boxed().collect(Collectors.toList());
        moneyList.sort(Collections.reverseOrder());
        couponList.sort(Collections.reverseOrder());

        int sum = 0;
        for(int i=0; i < moneyList.size(); i++){
            if(i >= couponList.size()) {
                System.out.println(moneyList.get(i));
                sum += moneyList.get(i); continue;
            }
            System.out.println(moneyList.get(i) * ((100-couponList.get(i))*0.01));
            sum += moneyList.get(i) * ((100-couponList.get(i))*0.01);
        }
        System.out.println(sum);
        return answer;
    }
}
