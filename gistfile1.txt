Re=[]
Visit=[]
def donuoc(x,y,z):
    #kiem tra
    if (y==2 or z==2):
        Re.append([x,y,z])
        return True
    #dfs
    if [x,y,z] in Visit:
        return False
    else:
        Visit.append([x,y,z]) 
    
    #CASE 1: Binh 1 chua day
    if x < 10:
        if (10-x) > z:
            if donuoc(x+z,y,0):
                Re.append([x+z,y,0])
                return True
        elif (10-x) <= z:
            if donuoc(10,y,z+x-10):
                Re.append([10,y,z+x-10])
                return True
        if (10-x) > y:
            if donuoc(x+y,0,z):
                Re.append([x+y,0,z])
                return True
        elif (10-x) <= y:
            if donuoc(10,y+x-10,z):
                Re.append([10,y+x-10,z])
                return True
    #CASE 2:Binh 2 chua day
    if y < 7:
        if (7-y) > x:
            if donuoc(0,y+x,z):
                Re.append([0,y+x,z])
                return True
        elif (7-y) <= x:
            if donuoc(x+y-7,7,z):
                Re.append([x+y-7,7,z])
                return True
        if (7-y) > z:
            if donuoc(x,y+z,0):
                Re.append([x,y+z,0])
                return True
        elif (7-y) <= z:
            if donuoc(x,7,z+y-7):
                Re.append([x,7,z+y-7])
                return True
    #CASE 3: Binh 3 chua day
    if z < 4:
        if (4-z) > y:
            if donuoc(x,0,z+y):
                Re.append([x,0,z+y])
                return True
        elif (4-z) <=y:
            if donuoc(x,y+z-4,4):
                Re.append([x,y+z-4,4])
                return True
        if (4-z) > x:
            if donuoc(0,y,z+x):
                Re.append([0,y,z+x])
                return True
        elif (4-z) <=x:
            if donuoc(x+z-4,y,4):
                Re.append([x+z-4,y,4])
                return True
    #Neu khong ton tai cach do tra ve FALSE
    return False
if donuoc(0,7,4):
    print("CO KET QUA!!!")
    print("Ban dau")
    print([0, 7, 4])
    while (len(Re)!=1):
        print("Next Step")
        print(Re.pop())
else:
    print("KHONG CO KET QUA DAU NHE!!!")

        
        
            
        
    

