import java.io.*;
import java.nio.file.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class FinancialFormatter{
    public static void main(String[] args){
        String MPs = getFileContents("file.txt");
        ArrayList<MP> MPAL = MPSplit(MPs);
        for(MP mp: MPAL){
            //System.out.println(mp);
        }
        //System.out.println(MPAL.get(2));
        //System.out.println(MPAL.size());

        String outputPath = "output.csv";
        try{
            FileWriter fW = new FileWriter(outputPath);
            BufferedWriter bW = new BufferedWriter(fW);

            String[] categories = populateCategories(MPAL);
            for(String s : categories){
            //    System.out.println(s);
            }
            String header = "Name," + String.join(",",categories);
            bW.write(header);
            bW.newLine();
            
            for(MP MP: MPAL){
                String dataLine = String.join(",",MP.getInterests());
                bW.write(dataLine);
                bW.newLine();
            }

            bW.close();

        } catch(Exception e){
            e.printStackTrace();
        }

        int input = 0;
        Scanner sc = new Scanner(System.in);
        while(input != -1){
            System.out.println("Print MP: ");
            input = sc.nextInt();
            System.out.println(MPAL.get(input));
        }
        sc.close();
         
    }

    public static ArrayList<MP> MPSplit(String MPs){
        ArrayList<MP> MPlist = new ArrayList<MP>();
        Scanner sc = new Scanner(MPs);
        MP current = new MP();
        boolean isActive = false;
        int index = -1;
        do{
            String line = sc.nextLine().trim();
            //System.out.println(index + " " + line);
            switch(line){
                case "":
                    MPlist.add(current);
                    isActive = false;
                    break;
                case "1":
                    index = 1;
                    break;
                case "2":
                    index = 2;
                    break;
                case "3":
                    index = 3;
                    break;
                case "4":
                    index = 4;
                    break;
                case "5":
                    index = 5;
                    break;
                case "6":
                    index = 6;
                    break;
                case "7":
                    index = 7;
                    break;
                case "8":
                    index = 8;
                    break;
                case "9":
                    index = 9;
                    break;
                case "10":
                    index = 10;
                    break;
                case "11":
                    index = 11;
                    break;
                case "12":
                    index = 12;
                    break;
                case "13":
                    index = 13;
                    System.out.println(line);
                    break;
                case "14":
                    index = 14;
                    break;
                default:
                    if(!isActive){
                        String tempLine = line.replace("Rt","").replace("Hon","").replace("Dr","").trim();
                        String[] temp = tempLine.split("\\(");
                        String[] temp2 = temp[1].replace(")","").split(", ");
                        current = new MP(temp[0].trim(), temp2[0].trim(), temp2[1].trim());
                        isActive = true;
                    } else {
                        current.interests.get(index-1).add(line);
                    }
                    break;
            }
        } while(sc.hasNextLine());
        sc.close();
        return MPlist;
    }

    public static String getFileContents(String fileName){
        String fileContents = "";
        try {
            fileContents = Files.readString(Path.of(fileName));
        } catch (IOException e) {
            System.out.println("File not found.");
        }
        return fileContents;
    }

    public static String[] populateCategories(ArrayList<MP> mpList){
        String[] out = new String[14];
        for(int i = 0; i < out.length; i++){
            for(MP mp : mpList){
                if(mp.interests.get(i).size() > 0){
                    out[i] = (i+1) + ": " + mp.interests.get(i).get(0);
                    break;
                }
            }
        }

        return out;
    }
        
}