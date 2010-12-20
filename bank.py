class BankAccount:

	interest_rate = 0.3

	def __init__(self,name,number,balance):
		self.name = name
		self.number = number
		self.balance = balance

	def deposit(self,amount):
		self.balance += amount
		print "balance is %d"%(self.balance)

	def withdraw(self,amount):
		if self.balance >= amount:
			self.balance -= amount
			print "Balance is %d"%(self.balance)
		else:
			print "No Enough Money"

	
	def add_interest(self):
		self.balance +=(self.balance * self.interest_rate);
		print "Current amount with interest is %d"%(self.balance)


class StudentAccount(BankAccount):

	limit = 1000
	
	def __init__(self, name, number, balance):
		BankAccount.__init__(self, name, number, balance)
		
	def withdraw(self,amount):
		if (self.balance-self.limit) >= amount:
			self.balance -= amount
			print "Balance is %d"%(self.balance)
		else:
			print "No Enough Money"
