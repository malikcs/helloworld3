window.onload = (function () {


var req = new XMLHttpRequest(); 
req.open('GET', 'http://127.0.0.1:3003/v1/ip', false); 
req.send(null);
if (req.status === 200) { 

    data = JSON.parse(req.response); 
    document.getElementById('content').innerHTML += "<p>IP terminal: "+data.ip+"</p>";
    console.log(data); 
}

function logResultat(messageHTML)
{
    document.getElementById('content').innerHTML += messageHTML; 
}
    //Ethernet
        document.getElementById('eth').addEventListener('click', function (e) {
                var exp = tetra.service({
                    service: 'local.desktopenv.explorer',
                    namespace: 'ingenico.desktopenv'
                });

                exp.reset()
                    .connect()
                    .call('SelectIcon', {data: {"entryUrl": "Control panel/Terminal settings/Communication means/Ethernet"}})
                    .error(function (e) {
                        logResultat( '<p style="color:red">Erreur ETH</p><p>' + e /*JSON.stringify(e)*/ + '</p>');
                    })
                    .success(function (e) {

                        stringHtml = '<p style="color:green">Succès ETH</p>';
                        logResultat( stringHtml);
                        console.log(e);

                    })
                    .disconnect();
        });

    //Get Params SDK
        document.getElementById('params').addEventListener('click', function (e) {

            var settingsService =   tetra.service({
            service: 'ingenico.software.SoftwareManagementServer',
            namespace: 'ingenico.software'});

            settingsService // Call the service
                .connect()
                .call('GetSoftwareManagementParameters') // Get the parameters
                .success(function (data) {
                    logResultat('<p>SDK: '+data.params.sdkVersion+"</p>");
                })
                .disconnect();
        });

        //PAY
        document.getElementById('paylink').addEventListener('click', function (e) {
            tetra
                .service({
                    service: 'local.transaction.engine',
                    namespace: 'ingenico.transaction',
                    formats: {
                        "StartRequest.tlv_inputData": "tlv",
                        "DoneEvent.tlv_resultData": "tlv"
                    }
                })
                .reset()
                .connect()
                .call('ManageTransaction', {
                    hide: true,
                    data: {
                        transaction: {
                            currency: {
                                code: 'EUR',
                                numCode: 978,
                                minorUnit: 2,
                                minorUnitSeparator: ",",
                                thousandSeparator: "",
                                position: "CURRENCY_BEFORE_AMOUNT",
                                symbol: "&amp;euro;"
                            },
                            value: "1000",
                            transactionType: "Payment"
                        },
                    }
                })
                .success(function (e) { 
                    logResultat('<p style="color:green">Succès transac</p>');
                })
                .error(function (e) {
                    logResultat(  '<p style="color:red">Erreur transac: ' + e.response.transactionDetails + '</p>');
                })
                .disconnect();
        });

        //IDLE
        document.getElementById('IDLE').addEventListener('click', function (e) {

            tetra.lookup("ingenico.emulation.EmulationTplus")
                .success(function(response){                    
                              emu = tetra.service({namespace:"ingenico.emulation", service: response.services[0].id});
                              emu.connect();
                              emu.call("StartIdleMessage");
                              emu.error(function (e) {
                        logResultat(  '<p style="color:red">Erreur IDLE: ' + e + '</p>');
                                })
                              emu.success(function (e) {
                        logResultat( '<p style="color:green">Succès IDLE</p>');
                                })
                             emu.disconnect();
                    })
                    .error(function (e) {
                        logResultat(  '<p style="color:red">Erreur EMU:</p><p>' + e + '</p>');
                    })

        });

        //passerelle
        document.getElementById('passerelle').addEventListener('click', function (e) {
                tetra.service({service: 'local.desktopenv.explorer', namespace: 'ingenico.desktopenv' })
                    .reset()
                    .connect()
                    .call('SelectIcon', {data: {"entryUrl": "Control panel/Config France?Type=MO&appliType=2"}})
                    .error(function (e) 
                    {
                        logResultat(  '<p style="color:red">Erreur passerelle: ' + JSON.stringify(e) + '</p>');
                    })
                    .success(function (e) 
                    {
                        logResultat( '<p style="color:green">Succès Passerelle</p>');
                        console.log(e);
                    })
                    .disconnect();
        });

        //dateAndTime
        document.getElementById('testDate').addEventListener('click', function (e) {
            var dandt = tetra.service({service: 'local.service.TimeAndDate',namespace: 'ingenico.dateAndTime'});
            dandt.reset()
            .connect()
			//.call('SelectIcon', {data: {"entryUrl": "Control panel/Terminal settings/Communication means/Ethernet"}})
			//.call('GetDate')
			.call('SetDate', {data: {"datestring": "02022000"}})
		//	.call('Test')
			.success( function(r){
                str = JSON.stringify(r);
				logResultat("<p>Success " + str + "</p>");
                console.log("Success dandT " + str);
            }).error( function(r){
                str = JSON.stringify(r);
				logResultat("<p>Erreur " + str + "</p>");
                console.log("Error dandT " +  str);
            }).disconnect();
            
            dandt.destroy();
        });
		
		//dateAndTime
        document.getElementById('testTime').addEventListener('click', function (e) {
            var dandt = tetra.service({service: 'local.service.TimeAndDate',namespace: 'ingenico.dateAndTime'});
            dandt.reset()
            .connect()
			//.call('SelectIcon', {data: {"entryUrl": "Control panel/Terminal settings/Communication means/Ethernet"}})
			//.call('GetDate')
			.call('SetTime', {data: {"timestring": "15:15"}})
		//	.call('Test')
			.success( function(r){
                str = JSON.stringify(r);
				logResultat("<p>Success " + str + "</p>");
                console.log("Success dandT " + str);
            }).error( function(r){
                str = JSON.stringify(r);
				logResultat("<p>Erreur " + str + "</p>");
                console.log("Error dandT " +  str);
            }).disconnect();
            
            dandt.destroy();
        });

		//TMS GetParam
        document.getElementById('TMSGetParam').addEventListener('click', function (e) {
            var dandt = tetra.service({service: 'local.service.TMSService',namespace: 'ingenico.TMSService'});
            dandt.reset()
            .connect()
			//.call('SelectIcon', {data: {"entryUrl": "Control panel/Terminal settings/Communication means/Ethernet"}})
			//.call('GetDate')
			.call('GetParam')
		//	.call('Test')
			.success( function(r){
                str = JSON.stringify(r);
				logResultat("<p>" + str.substring(0,60) + "</p>");
				logResultat("<p>" + str.substring(60,120) + "</p>");
				logResultat("<p>" + str.substring(120,180) + "</p>");
                console.log("Success dandT " + str);
            }).error( function(r){
                str = JSON.stringify(r);
				logResultat("<p>Erreur " + str + "</p>");
                console.log("Error dandT " +  str);
            }).disconnect();
            
            dandt.destroy();
        });
		
		//TMS SetParam
        document.getElementById('TMSSetParam').addEventListener('click', function (e) {
            var dandt = tetra.service({service: 'local.service.TMSService',namespace: 'ingenico.TMSService'});
            dandt.reset()
            .connect()
			//.call('SelectIcon', {data: {"entryUrl": "Control panel/Terminal settings/Communication means/Ethernet"}})
			//.call('GetDate')
			.call('SetParam', {data: {"tmsaddress": "91.208.214.34", "tcpport": "7019", "contractnumber": "010218225"}})
		//	.call('Test')
			.success( function(r){
                str = JSON.stringify(r);
				logResultat("<p>Success " + str + "</p>");
                console.log("Success dandT " + str);
            }).error( function(r){
                str = JSON.stringify(r);
				logResultat("<p>Erreur " + str + "</p>");
                console.log("Error dandT " +  str);
            }).disconnect();
            
            dandt.destroy();
        });
		
		
		//TMS Download
        document.getElementById('TMSDownload').addEventListener('click', function (e) {
            var dandt = tetra.service({service: 'local.service.TMSService',namespace: 'ingenico.TMSService'});
            dandt.reset()
            .connect()
			//.call('SelectIcon', {data: {"entryUrl": "Control panel/Terminal settings/Communication means/Ethernet"}})
			//.call('GetDate')
			.call('Download')
		//	.call('Test')
			.success( function(r){
                str = JSON.stringify(r);
				logResultat("<p>Success " + str + "</p>");
                console.log("Success dandT " + str);
            }).error( function(r){
                str = JSON.stringify(r);
				logResultat("<p>Erreur " + str + "</p>");
                console.log("Error dandT " +  str);
            }).disconnect();
            
            dandt.destroy();
        });
		
        //iScroll
        var myScroll = new IScroll('#wrapper', {
            scrollX: false,
            scrollY: true,
            lockDirection: true,
            disableTouch: true,
            disablePointer: true,
            useTransition: false,
            parentWrap: true,
            click: true
        });

    })();  