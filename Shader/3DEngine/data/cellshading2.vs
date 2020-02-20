////////////////////////////////////////////////////////////////////////////////
// Filename: color.vs
////////////////////////////////////////////////////////////////////////////////


/////////////
// GLOBALS //
/////////////
cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
	matrix worldInverseTranspose;
};


//////////////
// TYPEDEFS //
//////////////
struct VertexInputType
{
    float4 position : POSITION;
    float2 tex : TEXCOORD0;
    float4 normal : NORMAL;
    float4 color : COLOR;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
    float3 normal : TEXCOORD1;
    float4 color : COLOR;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType CellShadingVertexShader(VertexInputType input)
{
    PixelInputType output;

	// Change the position vector to be 4 units for proper matrix calculations.
    input.position.w = 1.0f;

	// Calculate the position of the vertex against the world, view, and projection matrices.
	float4 outputPos = mul(input.position, worldMatrix);
    outputPos = mul(outputPos, viewMatrix);
    outputPos = mul(outputPos, projectionMatrix);
    
	output.position = outputPos;


	/*output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);*/
    
	// Transform the normal
	output.normal = normalize(mul(input.normal, worldInverseTranspose));
 
	// Store the input color for the pixel shader to use.
    output.color = input.color;
    
	// Store the texture coordinates for the pixel shader.
	output.tex = input.tex;

    return output;
}