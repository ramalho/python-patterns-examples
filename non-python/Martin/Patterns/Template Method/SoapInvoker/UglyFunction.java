Vector d_params = new Vector();
d_params.addElement(
	new Parameter("name", String.class, "Robert", null));
d_params.addElement(
	new Parameter("id", int.class, new Integer(7734), null)

Call call = new Call();

call.setTargetObjectURI(d_objectUri);
call.setMethodName(d_methodName);
call.setEncodingStyleURI(d_encodingStyleURI);
call.setParams(d_params);

Response = d_resp;

// invoke the call.
try
{
    d_resp = call.invoke(s_url, "");
}
catch (SOAPException e)
{
    System.err.println("Caught SOAPException (" 
		+ e.getFaultCode() + "): " + e.getMessage());
}

Object rtnValue = null;
if (d_resp.generatedFault())
{
    outputFault(d_methodName, d_resp);
}
else
{
    Parameter ret = d_resp.getReturnValue();
    rtnValue = SoapUtils.fromByteArray((byte[]) ret.getValue());
}
