import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Ticketing {
    public static void main(String[] args) {

        // request 로그가 남고 1분이 지나면 티켓팅 성공
        // request 로그가 남고 1분이내에 나가면 leave 로그가 남는다. 59초 차이 안됨
        // 티켓팅에 성공한 사람들을 한번에 넘기기
        // 티켓은 구매한 유저는 다시 접속은 가능하지만 티켓 구매는 안됨
        int totalTicket = 2000;
        String[] logs = {
                "woni request 09:12:29",
                "brown request 09:23:11",
                "brown leave 09:23:44",
                "jason request 09:33:51",
                "jun request 09:33:56",
                "cu request 09:34:02"};

        Solution solution = new Solution();
        solution.solution(totalTicket, logs);
    }
}
class Solution {
    public String[] solution(int totalTicket, String[] logs){
        String[] answer = {};
        ArrayList<String> answer_list = new ArrayList<>(Arrays.asList(answer));
        ArrayList<String> payedUsers = new ArrayList<>();
        Session session = new Session();
        for (String sentence : logs){
            String[] actions = sentence.split(" ");
            String name = actions[0];
            String command = actions[1];
            LocalTime currentTime = LocalTime.parse(actions[2], DateTimeFormatter.ISO_LOCAL_TIME);
            if(command.equals("request")){
                if(session.isEmpty()){ session = new Session(name, command, currentTime); continue;}
                if(session.getCommand().equals("request") && session.isTicketingSuccess(currentTime) && answer_list.contains(name) == false){
                    answer_list.add(session.getName());
                    session.update(name, command, currentTime);
                }
                continue;
            }
            if(command.equals("leave")){
                if(session.getCommand().equals("request") && session.isTicketingSuccess(currentTime) && answer_list.contains(name) == false) {
                    answer_list.add(session.getName());
                }
                session.update(name, command, currentTime);
                session.clear();
            }
        }
        if(!session.isEmpty() && session.getCommand().equals("request")){
            answer_list.add(session.getName());
        }
        System.out.println(answer_list.toString());
        return answer;
    }
}
class Session {
    final LocalTime minTime = LocalTime.parse("09:00:00", DateTimeFormatter.ISO_LOCAL_TIME);
    final LocalTime maxTime = LocalTime.parse("10:00:00", DateTimeFormatter.ISO_LOCAL_TIME);

    private boolean status = true;
    private String name;
    private String command;
    private LocalTime time;

    public Session(){};
    public Session(String name, String command, LocalTime time){
        status = false;
        this.name = name;
        this.command = command;
        this.time = time;
    };

    public boolean isTicketingSuccess(LocalTime other){
        if(other.isAfter(maxTime)) return false;
        if(other.isBefore(minTime)) return false;
        long difference = time.until(other,ChronoUnit.SECONDS);
        if(difference < 60) return false;
        return true;
    }

    public void update(String name, String command, LocalTime time){
        this.name = name;
        this.command = command;
        this.time = time;
    }

    public void clear(){
        status = true;
    }
    public boolean isEmpty(){
        return status;
    }
    public String getName(){
        return name;
    }
    public String getCommand(){
        return command;
    }

}

