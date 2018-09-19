import java.io.*;
import java.util.Scanner;

class M10702114_hw1
{
	public static void main(String[] args)
	{
		// Init variable
		int min, max, ans, userinput;
		try
		{
			Scanner cin = new Scanner(System.in);
			// Read setting file
			FileReader inputFile = new FileReader("input.txt");
			BufferedReader in = new BufferedReader(inputFile);
			String buffer = in.readLine();
			min = Integer.parseInt(buffer);
			buffer = in.readLine();
			max = Integer.parseInt(buffer);
			buffer = in.readLine();
			ans = Integer.parseInt(buffer);

			// Start Game
			do {
				System.out.println("�п�J" + min + "~" + max + "�������Ʀr:");
				buffer = cin.nextLine();
				userinput = Integer.parseInt(buffer);
				if (userinput >= max || userinput <= min){
					System.out.println("�п�J�d�򤺪��ƭ�");
				} else if (userinput > ans) {
					max = userinput;
				} else if (userinput < ans) {
					min = userinput;
				} else {
					System.out.println("���ߧA����F");
				}
			} while (userinput != ans);
			cin.close();
			in.close();
		}catch(IOException e)
		{
			System.out.println(e);
		}
	}
}