#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long int

class CompanyInfo;

class StudentInfo
{
        public:
                ll minExpectedSalary;
                vector<CompanyInfo> companiesSelected;

                bool hired;
                ll money;

                CompanyInfo *selectedCompany;

                StudentInfo()
                {
                        hired = false;
                }

                void setMinSalary(int _minSalary)
                {
                        minExpectedSalary = _minSalary;
                }
};

class CompanyInfo
{
        public:
                int index;
                ll offeredSalary;
                ll maxJobOffers;
                int noOfStudents;
                vector<int> studentsIncoming;

                CompanyInfo()
                {
                        noOfStudents = 0;
                }

                void setValues(int _index, ll _offeredSalary, ll _maxJobOffers)
                {
                        index = _index;
                        offeredSalary = _offeredSalary;
                        maxJobOffers = _maxJobOffers;
                }

                bool isFull()
                {
                        return noOfStudents >= maxJobOffers;
                }

                void takeOne()
                {
                        noOfStudents++;
                }
};

bool compareCompanies(CompanyInfo c1, CompanyInfo c2)
{
        return (c1.offeredSalary > c2.offeredSalary);
}

int main()
{
        int t;
        scanf("%d", &t);
        while (t--) {
                int n, m;
                scanf("%d %d", &n, &m);
                StudentInfo studentInfo[n];
                CompanyInfo companyInfo[m];

                int i, j;
                ll minExpectedSalary;
                for (i = 0; i < n; i++) {
                        scanf("%lld", &minExpectedSalary);
                        studentInfo[i].setMinSalary(minExpectedSalary);
                }

                ll offeredSalary, maxJobOffers;
                for (i = 0; i < m; i++) {
                        scanf("%lld %lld", &offeredSalary, &maxJobOffers);
                        companyInfo[i].setValues(i, offeredSalary, maxJobOffers);
                }

                int status;
                for (i = 0; i < n; i++) {
                        char st[m + 1];
                        scanf("%s", st);
                        for (j = 0; j < m; j++) {
                                if (st[j]=='1') {
                                        studentInfo[i].companiesSelected.push_back(companyInfo[j]);
                                }
                        }
                }

                for (i = 0; i < n; i++) {
                        StudentInfo student = studentInfo[i];
                        for (j = 0; j < student.companiesSelected.size(); j++) {
                                CompanyInfo company = student.companiesSelected[j];
                                int cmpIndex = company.index;
                                if (student.minExpectedSalary > company.offeredSalary)
                                        break;
                                if (companyInfo[cmpIndex].isFull())
                                        break;
                                studentInfo[i].hired = true;
                                studentInfo[i].money = company.offeredSalary;
                                companyInfo[cmpIndex].takeOne();
                        }
                }
                int job = 0;
                ll totSalary = 0;
                int noSelect = 0;
                for (i = 0; i < n; i++) {
                        StudentInfo student = studentInfo[i];
                        if (student.hired) {
                                job++;
                                totSalary += student.money;
                        }
                }
                for (i = 0; i < m; i++) {
                        CompanyInfo company = companyInfo[i];
                        if (company.noOfStudents == 0)
                                noSelect++;
                }
                printf("%d %lld %d\n", job, totSalary, noSelect);
                /*
                for (i = 0; i < n; i++) {
                        StudentInfo student = studentInfo[i];
                        printf("Student: %d\n", i);
                        if (student.hired) {
                                printf("Salary: %lld\n", student.money);
                        } else {
                                printf("NOT HIRED\n");
                        }
                }
                */
                /*
                for (i = 0; i < n; i++) {
                        sort(studentInfo[i].companiesSelected.begin(), studentInfo[i].companiesSelected.end(), compareCompanies);
                        printf("Best options for student %d (%lld)\n", (i + 1), studentInfo[i].minExpectedSalary);
                        printf("Size: %d\n", studentInfo[i].companiesSelected.size());
                        for (j = 0; j < studentInfo[i].companiesSelected.size(); j++) {
                                printf("%lld ", studentInfo[i].companiesSelected[j].offeredSalary);
                        }
                        printf("\n");
                }
                */
        }
        return 0;
}
