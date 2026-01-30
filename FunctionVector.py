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
    def calculate_all(self):
        print('calculate_all')
		#Calculate the first trio
        matrix_1 = [[0,1,2,3,4,5,6,7,8,9],[0,1,2,3,4,5,6,7,8,9],[0,1,2,3,4,5,6,7,8,9]]
        for i,j,z in zip(matrix_1[0],matrix_1[1],matrix_1[2]):
            print(math.sqrt(((i*i) + (j*j)) * (z*z)))
            self.Tracker_Length_X.append(math.sqrt(((i*i) * (j*j)) * (z*z)))
            
   	
        matrix_2 = [[0,1,2,3,4,5,6,7,8,9],[9,8,7,6,5,4,3,2,1,0],[0,1,2,3,4,5,6,7,8,9]]
        for i,j,z in zip(matrix_2[0],matrix_2[1],matrix_2[2]):
            print(math.sqrt(((i*i) + (j*j)) * (z*z)))
            self.Tracker_Length_Y.append(math.sqrt(((i*i) * (j*j)) * (z*z)))
            
	
        matrix_3 = [[0,1,2,3,4,5,6,7,8,9],[0,1,2,3,4,5,6,7,8,9],[9,8,7,6,5,4,3,2,1,0]]
        for i,j,z in zip(matrix_3[0],matrix_3[1],matrix_3[2]):
            print(math.sqrt(((i*i) + (j*j)) * (z*z)))
            self.Tracker_Length_Z.append(math.sqrt(((i*i) * (j*j)) * (z*z)))
            
	
    def bestfit(self,trio_1,trio_2,trio_3):
        print('bestfit')
        tol = 4
        counter_1 = 0
        for number_1 in self.Tracker_Length_X:
         
            if number_1 < (trio_1 + tol) and number_1 > (trio_1 - tol):
               print(number_1)
               break
            counter_1 = counter_1 + 1
		
        counter_2 = 0
        for number_2 in self.Tracker_Length_Y:
         
            if number_2 < (trio_2 + tol) and number_2 > (trio_2 - tol):
               print(number_2)
               break
            counter_2 = counter_2 + 1
		
        counter_3 = 0
        for number_3 in self.Tracker_Length_Z:
         
            if number_3 < (trio_3 + tol) and number_3 > (trio_3 - tol):
                print(number_3)
                break
            counter_3 = counter_3 + 1
        
        return [counter_1,counter_2,counter_3]
		 		
##########################################################
#Created for manual testing of the methods on the class  #
##########################################################
def main():

    meInterfaceScript = clInterfaceScript()
    #Test the function manually
    meInterfaceScript.calculate_all()
    #To implement tolerances
    bestFitValue = meInterfaceScript.bestfit(8,8,8)
    
if __name__ == "__main__":
    main()
