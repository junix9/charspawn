// Creator: John Coleman
// Date: 05/03/2020
// Title: Password Generator using /dev/urandom
// Comment: 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char pass[255];
	char c;

	// Have user specify how many characters the password needs to be
	int amount;
	fprintf(stdout, "Please enter character amount: ");
	fscanf(stdin, "%i", &amount);
	if(amount < 10)
	{
		fprintf(stdout, "\nNOTE:\nThis won't be very secure, but okay...\n\n");
	}

	// Initialize loop counter, this also is our array pointer
	int x = 0;
	while(x < amount)
	{
		FILE *in = fopen("/dev/urandom", "r");
		char k;
		fscanf(in, "%c", &k);
		int value;
		value = k;
		
		//fprintf(stdout, "  %i   ", value);

		if(value > 32 && value < 127)
		{
			c = value;
			pass[x] = c;
			fclose(in);
			x++;
		}
		else
		{
			fclose(in);
			continue;
		}
	}

	pass[x] = '\0';

	fprintf(stdout, "\nYour new password is: \n\n%s\n\n", pass);
	return 0;
}
