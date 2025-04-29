class setop:
    def __init__(self):
        self.set1=[]
        self.set2=[]
        self.set3=[]

    def insert1(self,element):
        self.set1.append(element)

    def insert2(self,element):
        self.set2.append(element)

    def display(self):
        print("SET1::")
        print(set(self.set1))
        print("SET2::")
        print(set(self.set2))
    
    def delete1(self,element):
        if element in self.set1:
            self.set1.remove(element)
        else:
            print("Not found")

    def delete2(self,element):
        if element in self.set2:
            self.set2.remove(element)
        else:
            print("Not found")

    def Length(self):
        print("Size of set 1 is",len(self.set1))
        print("Size of set 2 is",len(self.set2))

    def Intersection(self):
        self.set3.clear()
        for element in self.set1:
            if element in self.set2:
                self.set3.append(element)

        print("Intersection is::")
        print(set(self.set3))

    def Union(self):
        self.set3.clear()
        for element in self.set1:
            self.set3.append(element)
        for element in self.set2:
            if element not in self.set3:
                self.set3.append(element)

        print("Union is::")
        print(set(self.set3))

    def difference(self):
        self.set3.clear()
        for element in self.set1:
            if element not in self.set2:
                self.set3.append(element)

        print("A-B::")
        print(set(self.set3))

    def checkelement1(self,element):
        if element in self.set1:
                print("Element Found",element)
        else:
                print("Element not found",element)
        



obj=setop()
choice=0
while(choice!=11):
    print("\n1.add in set1")
    print("\n2.add in set2")
    print("\n3.remove in set1")
    print("\n4.remove in set1")
    print("\n5.Length ")
    print("\n6.Union ")
    print("\n7.Intersection ")
    print("\n8.Difference ")
    print("\n9.check element from set 1")
    print("\n10.Display")
    print("\n11.Exit")
    
    choice=int(input("Enter your choice::"))
    if(choice==1):
        key=int(input("Enter your Element::"))
        obj.insert1(key)
    elif(choice==2):
        key=int(input("Enter your Element::"))
        obj.insert2(key)
    elif(choice==3):
        key=int(input("Enter your Element to remove::"))
        obj.delete1(key)
    elif(choice==4):
        key=int(input("Enter your Element to remove::"))
        obj.delete2(key)
    elif(choice==5):
        obj.Length()
    elif(choice==6):
        obj.Union()
    elif(choice==7):
        obj.Intersection()
    elif(choice==8):
        obj.difference()
    elif(choice==9):
        obj.checkelement1()
    elif(choice==10):
        obj.display()
    elif(choice==11):
        print("chale JA BSDK")
    else:
        print("Give correct option")