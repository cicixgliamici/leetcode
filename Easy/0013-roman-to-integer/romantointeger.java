import java.util.HashMap;
import java.util.Map;

class romantointeger {
    public int romanToInt(String s) {
        Map<Character, Integer> romanValues = new HashMap<>();
        romanValues.put('I', 1);
        romanValues.put('V', 5);
        romanValues.put('X', 10);
        romanValues.put('L', 50);
        romanValues.put('C', 100);
        romanValues.put('D', 500);
        romanValues.put('M', 1000);

        int total = 0;
        int i = 0;
        while (i < s.length()) {
            if (i + 1 < s.length() && romanValues.get(s.charAt(i)) < romanValues.get(s.charAt(i + 1))) {
                total += romanValues.get(s.charAt(i + 1)) - romanValues.get(s.charAt(i));
                i += 2;
            } else {
                total += romanValues.get(s.charAt(i));
                i++;
            }
        }
        return total;
    }
}