function  GetParams()
{
    var settingsService = tetra.service({
        service: 'local.software.management',
        namespace: 'ingenico.software'
    });


// Call the service
settingsService
    .connect()
    .call('GetParameters') // Get the parameters
    .then(function (data) {
        console.log(data);
    })
    .disconnect();
}

    
function Eth()
{
    var exp = tetra.service({     
    service: 'local.desktopenv.explorer',     
    namespace: 'ingenico.desktopenv' }); 

        exp.reset()
        .connect()
        //.call('GetShortcuts')
        //.call('GetIcons', {data: {"entryUrl": "Control panel/Terminal settings/Communication means/Ethernet"}})
        .call('SelectIcon', {data: {"entryUrl": "Control panel/Terminal settings/Communication means/Ethernet/dhcp"}})
        .error(function (e) {     
            document.getElementById('response').innerHTML = '<p style="color:red">Erreur:</p><p>'+  e /*JSON.stringify(e)*/ + '</p>';
        })
        .success(function (e) {

            stringHtml = '<p style="color:green">Succès:</p>';

            nb = e.icons.length;
            for (i = 0; i < nb; i++) 
            {
                stringHtml += '<p>'+ e.icons[i].entryUrl + '</p>';
            }
         /*   e.forEach(function(element) {
                stringHtml += '<p>'+ element.entryUrl+ '</p>';
                })
        */
            document.getElementById('response').innerHTML = stringHtml;
            console.log(e);

    })
        .disconnect();
}

function pay()
{
tetra
.service({
    service:  'local.transaction.engine',
    namespace: 'ingenico.transaction',
	formats: {
		"StartRequest.tlv_inputData": "tlv",
		"DoneEvent.tlv_resultData": "tlv"
	}
})
.reset()
.connect()
.call('ManageTransaction',{
    hide:true,
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
.success(function (e) 
{
	document.getElementById('response').innerHTML = '<p style="color:green">Succès:</p>';
  })
.error(function (e) 
{
	document.getElementById('response').innerHTML = '<p style="color:red">Erreur:</p><p>'+  e.response.transactionDetails + '</p>';
  })
.disconnect();
}

window.onload = (function() {

    document.getElementById('eth').addEventListener('click', function(e) {Eth();} );

    document.getElementById('params').addEventListener('click', function(e) {GetParams();} );

	document.getElementById('paylink').addEventListener('click', function(e) {pay();} );

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

	}	
)();
