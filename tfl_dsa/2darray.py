ROW =2
CLOUMN=5

class Plot :
    def __init__(self,plotId, crop_name,temperature, humidity,lightIntensity,co2, soilMoisture):
        self.crop_name=crop_name
        self.plotId=plotId
        self.temperature=temperature
        self.humidity=humidity
        self.lightIntensity=lightIntensity
        self.co2=co2
        self.soilMoisture=soilMoisture
        

    def display(self):
        print("Crop in this plot is ", self.crop_name)
        print("temperature is ",self.temperature)
        print("Humidity is ", self.humidity)
        print("lightintensity is ", self.lightIntensity)
        print("co2 level is ", self.co2)
        print("soil moisturer level is ", self.soilMoisture)
        print("*************************************************************")
Plots= [[0 for _ in range(CLOUMN)] for _ in range(ROW)]

Plots [0][0]= Plot(101,"onion",34,101,6999,3999,101)
Plots [0][1]= Plot(102,"potato",44,101,6999,3999,101)
Plots [0][2]= Plot(103,"raddish",32,101,6999,3999,101)
Plots [0][3]= Plot(104,"carrot",32,101,6999,3999,101)
Plots [0][4]= Plot(105,"cucumber",34,101,6999,3999,101)
Plots [1][0]= Plot(106,"spinach",34,101,6999,3999,101)
Plots [1][1]= Plot(107,"tomato",36,101,6999,3999,101)
Plots [1][2]= Plot(108,"beatroot",36,101,6999,3999,101)
Plots [1][3]= Plot(109,"brinjal",35,101,6999,3999,101)
Plots [1][4]= Plot(110,"coriander",33,101,6999,3999,101)

for i in range (ROW):
    for j in range (CLOUMN):
        Plots[i][j].display()