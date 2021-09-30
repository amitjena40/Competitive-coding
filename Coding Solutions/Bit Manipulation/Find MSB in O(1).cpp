
int findMSB(int n) {
	// Write your code here
	n = n | n >> 1;
	n = n | n >> 2;
	n = n | n >> 4;
	n = n | n >> 8;
	n = n | n >> 16;
	n += 1;
	return n >> 1;
}