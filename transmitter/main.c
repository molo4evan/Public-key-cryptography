#include "transmitter.h"

#ifdef DEBUG
void printMatrix(ulong *matrix, uchar size1, uchar size2);
#endif
/**
 *	Main block
 */
const uchar size = AMOUNT_OF_VARIABLES;

int main(int argc, char* argv[]) {
	ulong publicKey[2 * size * AMOUNT_OF_MEMBERS];	//	Correct Factor! It's ineffective memory using
	uchar encodedMessage[size * LENGTH_OF_ENCODED_NUMBER];
	ulong message[size];
	double tStart, tEnd, middleTimeOfCoding = 0;
#ifdef DEBUG
	uint count = 0;
	while (1) {
		count++;
#endif
		getPublicKey(publicKey);

		createMessage(message);
#ifdef DEBUG
		// printf("\n");
		// printMatrix(publicKey, size, AMOUNT_OF_MEMBERS);
		// printf("\n");
		printf("Message: ");
		for (int i = 0; i < size; i++) {
			printf("%llu ", message[i]);
		}
		printf("\n");

		tStart = getTime();
#endif
		coding(message, publicKey, encodedMessage);
#ifdef DEBUG
		tEnd = getTime();
		printf("Time of coding: %f ms\n", tEnd - tStart);
		middleTimeOfCoding += tEnd - tStart;

		printf("bytes: %d\n", returnEncodedMessage(encodedMessage));

		printf("Middle time:\n\
			Time of coding:  %f ms\n\
			", middleTimeOfCoding / count);
	}
#endif
#ifndef DEBUG
	returnEncodedMessage(encodedMessage);
#endif
	return 0;
}

#ifdef DEBUG
void printMatrix(ulong *matrix, uchar size1, uchar size2) {
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			printf("%llu ", matrix[i * size2 + j]);
		}
		printf("\n");
	}
}
#endif
