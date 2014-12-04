$(function () {

	var temp_anemo =[];
	var data1= [];
	var categories=[];
	console.log(temp_anemo.length);
	console.log(data1.length);
	console.log(categories.length);


	$.ajaxSetup({
	    async: false
	});

	$.getJSON("http://desplanchesdepalette.org/colibri/php/recupdata.php","id=45499", function (csv) {
		temp_anemo = JSON.parse(csv);
	});
	$.ajaxSetup({
	    async: true
	});

	var maxi =0;
	for (var i = 0; i<temp_anemo.length; i++){
		
		var line = temp_anemo[i];
		var value = parseInt(line[1]*4);
	
		if (value>maxi) maxi=value;
	}
	for (var i = 0; i<maxi;i++){
		data1[i]=0;	
	}

	for (var i = 0; i<temp_anemo.length; i++){
		var line = temp_anemo[i];
		anemo_value = parseInt(line[1]*4);
	
		data1[anemo_value]=data1[anemo_value]+1;
	}
	
	for (var i = 0; i<data1.length;i++){
		data1[i]=data1[i]/10;	
	}

	for (var i = 0; i<data1.length; i++){
		categories[i]=i/4;
	}
		console.log(temp_anemo.length);
	console.log(data1.length);
	console.log(categories.length	);

    $('#weibull').highcharts({
        chart: {
            type: 'column'
        },
        title: {
	        text: 'NetBoMo : Windspeed frequencies'
	    },
	subtitle: {
            text: 'Colibri, Eurre(26), France'
        },
        xAxis: {
            categories: categories,
	labels: {
        	rotation: -90,
		style: {
                    fontSize: '0.6em',
                    fontFamily: 'Verdana, sans-serif'
                }
              }   
        },
        yAxis: [{
            min: 0,
            title: {
                text: 'Wind (%)',
            },
		labels: {
                format: '{value}' ,
            }
        }],
        tooltip: {
	    headerFormat: '<span style="font-size:10px">{point.key}{series.name}:</br></span>',
            pointFormat: '<span style="font-size:10px"><b>{point.y:.1f}% </b></span>',
            shared: true,
            useHTML: true
        },
        plotOptions: {
            column: {
                pointPadding: 0.2,
                borderWidth: 0
            }
        },
        series: [{
            name: 'm/s',
            data: data1

        }]
    });
});
