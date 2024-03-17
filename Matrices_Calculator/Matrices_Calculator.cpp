#include<iostream>
using namespace std;

int main()
{

	cout << "========================= Welcome to Matrcies Calculator =========================" << endl
		 << "                          ***************************" <<endl<< endl;
	cout << "You can do any of these operations through our program and more ! :" << endl << endl;
	cout << "-Show Matrix Value: A" << endl <<
		    "-Addition: C = A + B" << endl <<
		    "-Subtraction : C = A - B" << endl <<
		    "-Multiplication : C = A * B" << endl <<
		    "-Transpose : C = A'" << endl <<
		    "-Division : C = A / B" << endl <<
		    "************************************" << endl;
	while (true)
	{

		int r1=0, c1=0;
		cout << "Note: the maximum size of matrix you can enter is 4x4 " << endl << endl;
		while (true)
		{
			cout << "Please enter the size of matrix A : " << endl << endl;
			cout << "-number of rows = ";
			while (!(cin >> r1))
			{
				cout << "input error !! : number of rows = ";
				cin.clear();
				cin.ignore(22, '\n');
			}
			cout << "-number of columns = ";
			while (!(cin >> c1))
			{
				cout << "input error !! : -number of columns = ";
				cin.clear();
				cin.ignore(22, '\n');
			}
			if (r1 < 1 || r1 > 4 || c1 < 1 || c1 > 4) { cout << "input error !!" << endl << endl; }
			else break;
		}
		int r2=0, c2=0;
		while (true)
		{
			cout << "Please enter the size of matrix B : " << endl << endl;
			cout << "-number of rows = ";
			while (!(cin >> r2))
			{
				cout << "input error !! : number of rows = ";
				cin.clear();
				cin.ignore(22, '\n');
			}
			cout << "-number of columns = ";
			while (!(cin >> c2))
			{
				cout << "input error !! : -number of columns = ";
				cin.clear();
				cin.ignore(22, '\n');
			}
			if (r2 < 1 || r2 > 4 || c2 < 1 || c2 > 4) { cout << "input error !!" << endl << endl; }
			else break;
		}

		double A[5][5];
		cout << endl << "please enter the numbers of matrix A :" << endl << endl;
		for (size_t i = 1; i <= r1; i++)
		{
			for (size_t j = 1; j <= c1; j++)
			{
				cout << "a" << i << j << ": ";
				while (!(cin >> A[i][j]))
				{
					cout << "input error !! : a" << i << j << ": ";
					cin.clear();
					cin.ignore(22, '\n');
				}
			}

		}
		double B[5][5];
		cout << endl << "please enter the numbers of matrix B :" << endl << endl;
		for (size_t i = 1; i <= r2; i++)
		{
			for (size_t j = 1; j <= c2; j++)
			{
				cout << "a" << i << j << ": ";
				while (!(cin >> B[i][j]))
				{
					cout << "input error !! : b" << i << j << ": ";
					cin.clear();
					cin.ignore(22, '\n');
				}
			}

		}

		while (true)
		{
			cout << endl << "Press 'A' to show matrix A and its determinant " << endl << endl;
			cout << "Press 'B' to show matrix B and its determinant " << endl << endl;
			cout << "Write 'A+B' to get the sum" << endl << endl;
			cout << "Write 'A-B' to get the subtraction" << endl << endl;
			cout << "Write 'A*B' to get the multiplication " << endl << endl;
			cout << "Press 'T' to get the transpose" << endl << endl;
			cout << "Write 'A/B' to get the division " << endl << endl;
			string x;
			// MATRIX A
			while(true)
			{
				cin >> x;
				if (x == "A")
				{
					cout << "matrix A : " << endl;
					for (size_t i = 1; i <= r1; i++)
					{
						for (size_t j = 1; j <= c1; j++)
						{
							cout << A[i][j] << " ";
						}
						cout << endl;
					}
					if (r1 == c1)
					{
						double det;
						if (c1 == 1)
						{
							det = A[1][1];
							cout << "the determinate of matrix A = " << det;
						}
						if (c1 == 2)
						{
							det = (A[1][1] * A[2][2]) - (A[1][2] * A[2][1]);
							cout << "the determinate of matrix A = " << det;
						}
						cout << endl;
						double m, n, l;
						if (c1 == 3)
						{
							m = A[1][1] * (A[2][2] * A[3][3] - A[2][3] * A[3][2]);
							n = A[1][2] * (A[2][1] * A[3][3] - A[2][3] * A[3][1]);
							l = A[1][3] * (A[2][1] * A[3][2] - A[2][2] * A[3][1]);
							det = m - n + l;
							cout << "the determinate of matrix A = " << det << endl;
						}
					}
					else cout << "the determinate can't be calculated" << endl
						<< "rows not equals columns " << endl << endl;
				}
				// MATRIX B
				else if (x == "B")
				{
					cout << "matrix B :" << endl;
					for (size_t i = 1; i <= r2; i++)
					{
						for (size_t j = 1; j <= c2; j++)
						{
							cout << B[i][j] << " ";
						}
						cout << endl;
					}
					if (r2 == c2)
					{
						double det;
						if (c2 == 1)
						{
							det = B[1][1];
							cout << "the determinate of matrix B = " << det;
						}
						if (c2 == 2)
						{
							det = (B[1][1] * B[2][2]) - (B[1][2] * B[2][1]);
							cout << "the determinate of matrix B = " << det << endl;
						}
						double m, n, l;
						if (c2 == 3)
						{

							m = B[1][1] * (B[2][2] * B[3][3] - B[2][3] * B[3][2]);
							n = B[1][2] * (B[2][1] * B[3][3] - B[2][3] * B[3][1]);
							l = B[1][3] * (B[2][1] * B[3][2] - B[2][2] * B[3][1]);
							det = m - n + l;
							cout << "the determinate of matrix B = " << det << endl;
						}

					}
					else cout << "the determinate can't be calculated " << endl
						<< "rows not equals columns " << endl << endl;



				}
				// Addition
				else if (x == "A+B")
				{
					if (r1 == r2 && c1 == c2)
					{
						double S[5][5];
						for (size_t i = 1; i <= c1; i++)
						{

							for (size_t j = 1; j <= r1; j++)
							{
								S[i][j] = A[i][j] + B[i][j];
							}
						}
						cout << "The sum of two matrcies is: " << endl << endl;
						for (size_t i = 1; i <= r1; i++)
						{
							for (size_t j = 1; j <= c1; j++)
							{
								cout << S[i][j] << " ";
							}
							cout << endl;
						}
					}
					else {
						cout << "the operation of sum can't be work" << endl
							<< "the size of two matrcies is not equal " << endl << endl;
					}
				}
				// Subtraction
				else if (x == "A-B")
				{
					if (r1 == r2 && c1 == c2)
					{
						double s[5][5];
						for (size_t i = 1; i <= c1; i++)
						{

							for (size_t j = 1; j <= r1; j++)
							{
								s[i][j] = A[i][j] - B[i][j];
							}
						}
						cout << "The subtraction of two matrcies is: " << endl << endl;
						for (size_t i = 1; i <= r1; i++)
						{
							for (size_t j = 1; j <= c1; j++)
							{
								cout << s[i][j] << " ";
							}
							cout << endl;
						}
					}
					else cout << "the operation of subtraction can't be work " << endl
						<< "the size of two matrcies is not equal " << endl << endl;
				}
				// Multiplication
				else if (x == "A*B")
				{
					double M[5][5];
					if (c1 == r2)
					{
						for (size_t i = 1; i <= r1; i++)
						{
							for (size_t j = 1; j <= c2; j++)
							{
								M[i][j] = 0;
							}
						}
						for (size_t i = 1; i <= r1; i++)
						{
							for (size_t j = 1; j <= c2; j++)
							{
								for (size_t t = 1; t <= c1; t++)
								{
									M[i][j] = M[i][j] + A[i][t] * B[t][j];
								}
							}
						}
						cout << "The multiplication of two matrcies is: " << endl << endl;
						for (size_t i = 1; i <= r1; i++)
						{
							for (size_t j = 1; j <= c2; j++)
							{
								cout << M[i][j] << " ";
							}
							cout << endl;
						}
					}
					else cout << "the operation of multiplication can't be work  " << endl
						<< "columns of matrix A must be equal to rows of matrix B " << endl << endl;
				}
				// Transpose
				else if (x == "T")
				{
					cout << endl << "For matrix A or matrix B ?" << endl;
					char z = 0; cin >> z;
					if (z == 'A')
					{
						cout << "the transpose of matrix A : " << endl << endl;
						for (size_t i = 1; i <= c1; i++)
						{

							for (size_t j = 1; j <= r1; j++)
							{
								cout << A[j][i] << " ";
							}
							cout << endl;
						}
					}
					else if (z == 'B')
					{
						cout << "the transpose of matrix B : " << endl << endl;
						for (size_t i = 1; i <= c2; i++)
						{

							for (size_t j = 1; j <= r2; j++)
							{
								cout << B[j][i] << " ";
							}
							cout << endl;
						}
					}
					else;

				}
				else if (x == "A/B")
				{
					if (r2 == c2 && r1 == r2 && c1 == c2)
					{
						double det, D[5][5];
						if (c1 == 1)
						{
							double  IB[1][1]; //IB:Inverse of matrix B
							det = B[1][1];
							if (det == 0)
							{
								cout << " " << "the operation of division can't be work  " << endl;
								cout << " " << "determinant of matrix B is equal to zero so matrix B is not invertible" << endl;


							}
							else
							{
								IB[1][1] = 1 / det * B[1][1];
								for (size_t i = 1; i <= r1; i++)
								{
									for (size_t j = 1; j <= c2; j++)
									{
										D[i][j] = 0;
									}
								}
								for (size_t i = 1; i <= r1; i++)
								{
									for (size_t j = 1; j <= c2; j++)
									{
										for (size_t t = 1; t <= c1; t++)
										{
											D[i][j] = D[i][j] + A[i][t] * IB[t][j];
										}
									}
								}
								cout << "The division of two matrcies is: " << endl << endl;
								for (size_t i = 1; i <= r1; i++)
								{
									for (size_t j = 1; j <= c2; j++)
									{
										cout << D[i][j] << " ";
									}
									cout << endl;
								}
							}
						}
						if (c2 == 2)//(2x2)
						{
							double  IB[2][2]; //IB:Inverse of matrix B
							det = (B[1][1] * B[2][2]) - (B[1][2] * B[2][1]);
							if (det == 0)
							{
								cout << " " << "the operation of division can't be work  " << endl;
								cout << " " << "determinant of matrix B is equal to zero so matrix B is not invertible" << endl;


							}
							else
							{
								det = (B[1][1] * B[2][2]) - (B[1][2] * B[2][1]);

								swap(B[1][1], B[2][2]);
								B[1][2] = -B[1][2];
								B[2][1] = -B[2][1];
								for (size_t i = 1; i <= r2; i++)
								{
									for (size_t j = 1; j <= c2; j++)
									{

										IB[i][j] = (1 / det) * B[i][j];
									}
								}

								for (size_t i = 1; i <= r1; i++)
								{
									for (size_t j = 1; j <= c2; j++)
									{
										D[i][j] = 0;
									}
								}
								for (size_t i = 1; i <= r1; i++)
								{
									for (size_t j = 1; j <= c2; j++)
									{
										for (size_t t = 1; t <= c1; t++)
										{
											D[i][j] = D[i][j] + A[i][t] * IB[t][j];
										}
									}
								}
								cout << "The division of two matrcies is: " << endl << endl;
								for (size_t i = 1; i <= r1; i++)
								{
									for (size_t j = 1; j <= c2; j++)
									{
										cout << D[i][j] << " ";
									}
									cout << endl;
								}

							}
						}



						if (c2 == 3)//(3x3)
						{
							double IB[4][4];//IB:Inverse of matrix B
							double m, n, l;
							m = B[1][1] * (B[2][2] * B[3][3] - B[2][3] * B[3][2]);
							n = B[1][2] * (B[2][1] * B[3][3] - B[2][3] * B[3][1]);
							l = B[1][3] * (B[2][1] * B[3][2] - B[2][2] * B[3][1]);
							det = m - n + l;

							if (det == 0)
							{
								cout << " " << "the operation of division can't be work  " << endl;
								cout << " " << "determinant of matrix B is equal to zero so matrix B is not invertible" << endl;

							}
							else
							{
								m = B[1][1] * (B[2][2] * B[3][3] - B[2][3] * B[3][2]);
								n = B[1][2] * (B[2][1] * B[3][3] - B[2][3] * B[3][1]);
								l = B[1][3] * (B[2][1] * B[3][2] - B[2][2] * B[3][1]);
								det = m - n + l;
								double a, b, c, d, e, f, g, h, i;
								a = (B[2][2] * B[3][3] - B[2][3] * B[3][2]);
								b = -(B[2][1] * B[3][3] - B[2][3] * B[3][1]);
								c = (B[2][1] * B[3][2] - B[2][2] * B[3][1]);

								d = -(B[1][2] * B[3][3] - B[1][3] * B[3][2]);
								e = (B[1][1] * B[3][3] - B[1][3] * B[3][1]);
								f = -(B[1][1] * B[3][2] - B[1][2] * B[3][1]);

								g = (B[1][2] * B[2][3] - B[1][3] * B[2][2]);
								h = -(B[1][1] * B[2][3] - B[1][3] * B[2][1]);
								i = (B[1][1] * B[2][2] - B[1][2] * B[2][1]);

								B[1][1] = a;
								B[1][2] = b;
								B[1][3] = c;
								B[2][1] = d;
								B[2][2] = e;
								B[2][3] = f;
								B[3][1] = g;
								B[3][2] = h;
								B[3][3] = i;

								swap(B[1][2], B[2][1]);
								swap(B[1][3], B[3][1]);
								swap(B[2][3], B[3][2]);

								for (size_t i = 1; i <= r2; i++)
								{
									for (size_t j = 1; j <= c2; j++)
									{

										IB[i][j] = (1 / det) * B[i][j];
									}
								}

								for (size_t i = 1; i <= r1; i++)
								{
									for (size_t j = 1; j <= c2; j++)
									{
										D[i][j] = 0;
									}
								}
								for (size_t i = 1; i <= r1; i++)
								{
									for (size_t j = 1; j <= c2; j++)
									{
										for (size_t t = 1; t <= c1; t++)
										{
											D[i][j] = D[i][j] + A[i][t] * IB[t][j];
										}
									}
								}
								cout << "The division of two matrcies is: " << endl << endl;
								for (size_t i = 1; i <= r1; i++)
								{
									for (size_t j = 1; j <= c2; j++)
									{
										cout << D[i][j] << " ";
									}
									cout << endl;
								}
							}
						}
					}
					else
					{
						cout << "the operation of division can't be work  " << endl
							<< "matrix B must be a square matrix (rows=columns)" << endl
							<< "AND" << endl
							<< "the two matrices must have the same size" << endl;
					}
				}
				if (x == "A" || x == "B" || x == "A+B" || x == "A-B" || x == "A*B" || x == "A/B" || x == "T") { break; }
				else { cout << "input error !!" << endl << endl; }
			}



			cout << endl;
			cout << "if you want to do another operation write 'O' : " << endl;
			cout << "if you want to exit or restart with new matrcies press any key" << endl;
			string y;
			cin >> y;
			if (y == "O" || y== "o")
			{
				cout << endl;
			}
			else { break; }

		}
		cout << endl;
		cout << "Thanks for using our program" << endl << endl;
		cout << "To quit Write 'exit'" << endl;
		cout << "To restart with new matrcies Write 'R'" << endl;
		cout << endl;
		string z;
		cin >> z;
		if (z == "exit" || z== "EXIT")
		{
			break;
		}
		else if (z == "R" || z=="r")
		{
			cout << endl;
		}
	}

}
