$(function () {

	var temp_anemo =[];
    	var temp_dir =[];
	var columns = 16;
	var data1= new Array();
	var data2 =new Array();
	var data3 =new Array();
	var data4 =new Array();

    var options = {
        
	    chart: {
		
	        renderTo: 'container',
	        polar: true,
		type: 'column'
	    },
	    
	    title: {
	        text: 'NetBoMo : Windspeed distribution'
	    },
	subtitle: {
            text: 'Colibri, Eurre(26), France in 1/1000'
        },
	    legend: {
            	reversed: false,
            	align: 'right',
            	verticalAlign: 'top',
            	y: 100,
            	layout: 'vertical'
            },
	    pane: {
	        startAngle: 0,
	        endAngle: 360
	    },
	
	    xAxis: {
            type: "",
            categories: ['N','NNE','NE','NEE','E','SEE','SE','SSE','S','SSO','SO','SOO','O','NOO','NO','NNO'],           
	        labels: {
	        	formatter: function () {
	        		return this.value;
	        	}
	        },
		tickmarkPlacement: 'on'
	    },
	        
	    yAxis: {
	        min: 0
	    },
	    
	    plotOptions: {
            	series: {
			pointPlacement: 'on',
			stacking: 'normal',
	        },
	        column: {
	            pointPadding: 0,
	            groupPadding: 0
	        }
	    },

	    series: [
		{
		name: '>12m/s',
		data: data4
		},
		{
		name: '8-12m/s',
		data: data3
		},
		{
		name: '3-8m/s',
		data: data2
		},
		{
		name: '<3m/s',
		data: data1
		}
		]
			
	}
	$.ajaxSetup({
	    async: false
	});

	
	$.getJSON("http://desplanchesdepalette.org/colibri/php/recupdata.php","id=45499", function (csv) {
		temp_anemo = JSON.parse(csv);
	});
	
	$.getJSON("http://desplanchesdepalette.org/colibri/php/recupdata.php","id=45500", function (diro) {
		temp_dir = JSON.parse(diro);
	});

	
	$.ajaxSetup({
		async: true
	});

	for (i =0; i<16; i++){
		data1[i] = 0;
		data2[i] = 0;
		data3[i] = 0;
		data4[i] = 0;
	}


	for (var i = 0; i<temp_anemo.length; i++){
		var line_a = temp_anemo[i];
		var line_d = temp_dir[i];

		anemo_value = parseFloat(line_a[1]);
		dir_value = parseInt(line_d[1]);

		if (anemo_value<3){
		var tmp = data1[dir_value]+1
		data1[dir_value] = tmp;
		}else if (anemo_value>=3 && anemo_value<8){
		var tmp = data2[dir_value]+1; 
		data2[dir_value] = tmp;
		}else if (anemo_value>=8 && anemo_value<12){
		var tmp = data3[dir_value]+1; 
		data3[dir_value] = tmp;
		}else{
		var tmp = data4[dir_value]+1; 
		data4[dir_value] = tmp;
		}
	};
	
	window.chart = new Highcharts.Chart(options);
});
