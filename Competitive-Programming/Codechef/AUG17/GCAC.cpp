#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

#define ll long long int

class CompanyInfo;

class StudentInfo
{
        public:
                ll minSalary;
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
                        minSalary = _minSalary;
                }
};

class CompanyInfo
{
        public:
                int index;
                ll offeredSalary;
                ll maxJobOffers;
                int noOfStudents;

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


                string s[n];
                for (i = 0; i < n; i++) {
                        cin >> s[i];
                }

                int jobbed = 0;
                ll totalSalary = 0;
                for (i = 0; i < n; i++) {
                        ll minSalary = studentInfo[i].minSalary;
                        ll maxSalaryOffered = -1;
                        int selectedCompanyIndex = -1;
                        for (j = 0; j < m; j++) {
                                if (s[i][j] == '1') {
                                        if (maxSalaryOffered < companyInfo[j].offeredSalary && !companyInfo[j].isFull()) {
                                                maxSalaryOffered = companyInfo[j].offeredSalary;
                                                selectedCompanyIndex = j;
                                        }
                                }
                        }
                        if (minSalary <= maxSalaryOffered) {
                                companyInfo[selectedCompanyIndex].takeOne();
                                studentInfo[i].hired = true;
                                jobbed++;
                                totalSalary += maxSalaryOffered;
                        }
                }
                int neijob = 0;
                for (i = 0; i < m; i++) {
                        if (companyInfo[i].noOfStudents == 0)
                                neijob++;
                }
                printf("%d %lld %d\n", jobbed, totalSalary, neijob);
                /*
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

                
                

                for (i = 0; i < n; i++)
                        sort(studentInfo[i].companiesSelected.begin(), studentInfo[i].companiesSelected.end(), compareCompanies);

                for (i = 0; i < n; i++) {
                        for (j = 0; j < m; j++) {
                                printf("%c ", st[i]);
                        }
                }
                
                for (i = 0; i < n; i++) {
                        StudentInfo student = studentInfo[i];
                        for (j = 0; j < student.companiesSelected.size(); j++) {
                                CompanyInfo company = student.companiesSelected[j];
                                int cmpIndex = company.index;
                                if (student.minSalary > company.offeredSalary)
                                        continue;
                                if (companyInfo[cmpIndex].isFull())
                                        continue;
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
                */
        }
        return 0;
}
