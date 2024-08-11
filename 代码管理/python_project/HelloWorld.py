#设计一个类，其中属性包含（姓名、性别、国籍、籍贯、年龄）
class person:
    def __init__(self,name,age,gender,nationality,place):
        self.mname=name
        self.mage=age
        self.mgender=gender
        self.mnationality=nationality
        self.mwork_place=place
        print(f"Student类创建了一个对象")

p1=person("老王",30,"男","中国","上海市")#创建类对象，并给类对象赋值
print(f"他的姓名{p1.mname},他的年龄{p1.mage},他的性别{p1.mgender},\n他的国籍为{p1.mnationality},他的居住地{p1.mwork_place}")12
