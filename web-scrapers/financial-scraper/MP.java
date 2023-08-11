import java.util.ArrayList;

public class MP{
    public String name;
    public String electorate;
    public String party;
    public ArrayList<ArrayList<String>> interests;

    public MP(String name, String party, String electorate){
        this.name = name;
        this.electorate = electorate;
        this.party = party; 
        interests = new ArrayList<ArrayList<String>>();
        for(int i = 0; i < 14; i++){
            ArrayList<String> temp = new ArrayList<String>();
            interests.add(temp);
        }
    }

    public MP(){}

    public String toString(){
        String out = name + " (" + party + ", " + electorate + ")\n";
        for(ArrayList<String> list : interests){
            if(list.size() > 0){
                out += list.toString() + "\n";
            }
        }
        return out;
    }

    public String[] getInterests(){
        String[] in = new String[15];
        in[0] = name;
        for(int j = 0; j < interests.size(); j++){
            ArrayList<String> aL = interests.get(j);
            String temp = "";
            for(int i = 1; i < aL.size(); i++){
                temp += aL.get(i);
                if(i != aL.size()-1){
                    temp += "|";
                }
            }
            in[j+1] = "\"" + temp + "\"";
        }
        return in;
    }
}