import math
#####################################
#Fill in the classname of the object#
#####################################
class clInterfaceScript:
    #####################################
    #Constructor class (stay's this way)#
    #####################################
    def __init__(self):
        print ('clInterfaceScript::__init__->start')
        self.Tracker_CoordX=[]
        self.Tracker_Length_X=[]
        self.Tracker_CoordY=[]
        self.Tracker_Length_Y=[]
        self.Tracker_CoordZ=[]
        self.Tracker_Length_Z=[]

        try:
            print ('clInterfaceScript::__init__->start')
        except:
            traceback.print_exc()
    ####################################
    #Destructor class (stay's this way)#
    ####################################
    def __del__(self):
        print ('clInterfaceScript::__del__->start')

    ###########
    #Functions#
    ###########
    def calculate_all_trio(self,x_dimension,y_dimension,z_dimension):
        print('calculate_all_trio')
        i = 0
        j = 0
        z = 0

		#Calculate the first trio
        while i < x_dimension:
             while j < y_dimension:	
                 while z < z_dimension:
                    self.Tracker_CoordX.append([i,j,z])
                    v = math.sqrt((i*i)+(j*j))
                    p = math.sqrt((v*v)+(z*z))
                    self.Tracker_Length_X.append(p)
                    z = z + 1
                 z = 0   
                 j = j + 1
             j = 0    
             i = i + 1
   	
		#Calculate the second trio
        i=0
        j=1000
        z=0
		
        while i < x_dimension:
            while j > -1:
                while z < z_dimension:
                    self.Tracker_CoordY.append([i,j,z])
                    v = math.sqrt((i*i)+(j*j))
                    p = math.sqrt((v*v)+(z*z))
                    self.Tracker_Length_Y.append(p) 
                    z = z + 1
                z = 0    
                j = j - 1
            j = 1000    
            i = i + 1
	    #Calculate the third trio
        i=1000
        j=0
        z=0
		
        while i > -1:
           while j < y_dimension:
               while z < z_dimension:
                    self.Tracker_CoordZ.append([i,j,z])
                    v = math.sqrt((i*i)+(j*j))
                    p = math.sqrt((v*v)+(z*z))
                    self.Tracker_Length_Z.append(p)
                    z = z + 1
               z = 0     
               j = j + 1
           j = 0    
           i = i - 1
    def bestfit_trio(self,trio_1,trio_2,trio_3):
        tol = 20
        counter_1 = 0
        for number_1 in self.Tracker_Length_X:
            if number_1 < (trio_1 + tol) and number_1 > (trio_1 - tol):
               break
            counter_1 = counter_1 + 1
		
        counter_2 = 0
        for number_2 in self.Tracker_Length_Y:
            if number_2 < (trio_2 + tol) and number_2 > (trio_2 - tol):
               break
            counter_2 = counter_2 + 1
		
		
        counter_3 = 0
        for number_3 in self.Tracker_Length_Z:
            if number_3 < (trio_3 + tol) and number_3 > (trio_3 - tol):
                break
            counter_3 = counter_3 + 1
        
        print('Vector 1:' + str(self.Tracker_CoordX[counter_1]))
        print('Vector 2:' + str(self.Tracker_CoordY[counter_2]))
        print('Vector 3:' + str(self.Tracker_CoordZ[counter_3]))
        
        return [counter_1,counter_2,counter_3]
		 		
##########################################################
#Created for manual testing of the methods on the class  #
##########################################################
def main():

    meInterfaceScript = clInterfaceScript()
    #Test the function manually
    meInterfaceScript.calculate_all_trio(1000,1000,1000)
    #To implement tolerances
    bestFitValue = meInterfaceScript.bestfit_trio(700,700,700)
    
if __name__ == "__main__":
    main()
